# Meal planner agent

A personal agent persona that suggests meals, remembers what you like, and avoids proposing the same thing twice. Made to run in agent tools that read workspace instruction files and can read/write files, like [OpenClaw](https://openclaw.ai) or [Hermes Agent](https://hermes-agent.nousresearch.com).

## How it works

You: *"Propose meals for the next 3 days."*

1. **First time only**: your taste profile is empty, so the agent asks ~10 quick questions (servings, allergies, likes, dislikes, time, equipment...).
2. **Feedback**: it asks how the meals you picked last time were, on a 1–5 scale.
3. **Questionnaire**: for each meal slot it proposes 3 options (name, short description, time). No recipes yet. You answer like `Mon c, Tue a, Wed b`, or with buttons if your chat app supports them.
4. **Recipes**: for the meals you picked, it gives ingredients and steps.
5. **On demand**: more details on a step, or a shopping list grouped by store section.

Anytime you say something like *"I don't like fish"* or *"I have no oven"*, the agent writes it to your taste profile and takes it into account from then on.

### Memory

| File | Content | Shareable? |
|---|---|---|
| `AGENTS.md` | How the agent works: workflow, selection rules, questionnaire formats | Yes, generic |
| `SOUL.md` | Personality and tone | Yes, generic |
| `templates/` | Empty versions of the memory files | Yes |
| `data/taste_profile.md` | Your likes, dislikes, allergies, habits, equipment, pantry | **No, personal** |
| `data/meal_history.md` | Every meal proposed, picked or not, with its rating | **No, personal** |

The agent creates `data/` from `templates/` on first use. `data/` is git-ignored, so sharing this folder never shares anyone's personal data.

### Re-proposal rules

Nothing proposed in the last 14 days comes back. After that, meals come back depending on their rating: **5** after 3 weeks, **4** after 6 weeks, **3** after 3 months, **1–2** never. Meals proposed but never picked can come back after 4 weeks. Each slot usually mixes one past favorite, one new meal close to your taste, and one new meal that's a bit of a stretch.

To change these rules, edit "Selection rules" in `AGENTS.md`.

## Setup

The agent needs its own workspace folder containing these files, with read/write access to it.

### OpenClaw

OpenClaw reads `AGENTS.md` and `SOUL.md` from the agent's workspace. Create a dedicated agent so it has its own workspace and memory, separate from your main one:

```sh
openclaw agents add meal-planner
cp -r AI_agents/meal_planner/{AGENTS.md,SOUL.md,templates} ~/.openclaw/workspace-meal-planner/
```

Use the workspace path that `openclaw agents add` printed if it differs. If the workspace already has an `AGENTS.md`/`SOUL.md`, append these files' content instead of overwriting.

### Hermes Agent

Hermes loads `SOUL.md` as the persona and `AGENTS.md` from the working directory. Give the meal planner its own folder and start Hermes from it:

```sh
mkdir -p ~/agents/meal-planner
cp -r AI_agents/meal_planner/{AGENTS.md,SOUL.md,templates} ~/agents/meal-planner/
cd ~/agents/meal-planner && hermes
```

If you use Hermes profiles, put `SOUL.md` in the profile's home folder instead.

### Other tools (Claude Code, Codex, Cursor...)

Any tool that reads `AGENTS.md` (or `CLAUDE.md`) from the working directory works: copy the folder somewhere and start the tool from it. For Claude Code, add a `CLAUDE.md` containing `@AGENTS.md` and `@SOUL.md`.

> Tool setups change often. If a command above doesn't match your version, check the tool's docs for "workspace" or "context files"; all the agent needs is to load `AGENTS.md` + `SOUL.md` and to be able to write to `data/`.

## Usage examples

- *"What should I cook for the next 3 days? Dinners only, 2 people."*
- *"Plan lunch and dinner for the weekend, I have guests on Saturday."*
- *"Meals for 3 days, I have leeks, chorizo and cream to use up."* → used as inspiration, left off the shopping list
- *"I picked Mon b, Tue a, Wed c."*
- *"Give me the shopping list."*
- *"How do I know when the risotto is done?"*
- *"I don't like coriander."* → saved to your profile
- *"Show me my taste profile."* / *"What did I rate highest?"*

You can also edit `data/taste_profile.md` by hand at any time.

## Sharing

Share the whole `meal_planner/` folder, without `data/`. The other person gets the onboarding questionnaire on their first request and builds their own profile.
