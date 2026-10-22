# German teacher agent

A German learning companion for bite-size, regular practice. It tests your level once, then gives you a short session every day, remembers every topic you've seen and how well you know it, and brings old topics back before you forget them.

Made for agent tools that read workspace instruction files and can read/write files, like [OpenClaw](https://openclaw.ai) or [Hermes Agent](https://hermes-agent.nousresearch.com).

## How it works

1. **Placement test (first time)**: a few questions about you (native language, goals, time per day, interests), then 2–3 short rounds of questions that get harder as long as you're doing well. You can stop anytime and continue another day.
2. **Daily session (~5–10 min)**:
   - a quick warm-up on topics due for review,
   - a mini-lesson on one new topic, with examples first and the rule after,
   - 3–5 short exercises, then corrections with one-line explanations,
   - "too easy / just right / too hard?" so the agent can adapt.
   During the first 10 sessions there is only **one theme per session**, to keep it simple.
3. **Mini mode**: no energy today? Ask for a mini session: 3 questions, 2 minutes.
4. **Questions anytime**: ask for more examples, a re-explanation, or how to say something. Real topics you ask about get added to your review list.

### Spaced review

Each topic has a mastery level from 0 to 5. Good results raise it, struggles lower it, and the level sets when the topic comes back: from the next day (0) up to one month later (5). No topic is ever "done": even solid ones come back monthly. Recurring mistakes are noted and targeted in reviews.

### Memory

| File | Content | Shareable? |
|---|---|---|
| `AGENTS.md` | How the agent works: placement test, sessions, review rules | Yes, generic |
| `SOUL.md` | Personality and tone | Yes, generic |
| `templates/` | Empty versions of the memory files | Yes |
| `data/learner_profile.md` | Your level per skill, goals, interests, what works for you | **No, personal** |
| `data/topic_tracker.md` | Every topic seen, mastery, next review date, recurring mistakes | **No, personal** |
| `data/session_log.md` | One line per session: topics, score, how it felt | **No, personal** |

The agent creates `data/` from `templates/` on first use. `data/` is git-ignored.

## Setup

The agent needs its own workspace folder containing these files, with read/write access to it. Setup is the same as the [meal planner](../meal_planner/README.md#setup), replacing `meal_planner`/`meal-planner` with `german_teacher`/`german-teacher`.

### Daily reminder

The agent can't message you on its own unless your tool schedules it. To get a lesson every day:
- **OpenClaw / Hermes**: both support scheduled (cron) tasks sent to an agent. Schedule a daily message such as *"Start today's German session"* to this agent, at a time that suits you (e.g. on your commute).
- **Other tools**: just open a chat with the agent and say hi.

> Tool setups change often. If something doesn't match your version, check the tool's docs for "workspace", "context files" and "cron" / "scheduled tasks".

## Usage examples

- *"Hallo!"* / *"Today's lesson"* → daily session
- *"Mini session please, I'm tired."*
- *"I didn't get exercise 3, can you explain again?"*
- *"Give me more examples with the dative."*
- *"How do I say 'I'd like to book a table for two'?"*
- *"That was way too easy."* → difficulty goes up
- *"What have I learned so far?"* / *"Which topics are still weak?"*
