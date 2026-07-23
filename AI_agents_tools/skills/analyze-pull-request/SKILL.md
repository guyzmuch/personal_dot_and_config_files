---
name: analyze-pull-request
description: >-
  Infer the purpose of the current branch from its local git diff vs main or
  master, suggest improvements, and note alternative approaches. Use when the
  user asks to analyze or review their branch or MR. Local diff only — no fetch,
  no branch switch, no opening files.
disable-model-invocation: true
---

# Analyze Pull Request / Merge Request

Infer **purpose from the diff**, not MR title or description. The user controls their repo state — assume it is already up to date.

**Scope:** current branch vs local `main` or `master` only. Nothing else.

## Gather context

Run **only** these local git commands. Use `main` if it exists locally, otherwise `master`:

```bash
git branch --show-current
git log <base>..HEAD --oneline
git diff <base>...HEAD
```

Replace `<base>` with `main` or `master`. Say which base you used.

Analyze **only** from that command output. Do not open, read, or search files in the repo.

## Do not

- `git fetch` or any network/git remote sync
- `git checkout`, `git switch`, or change branches
- Use `glab`, `gh`, or any MR/PR API/CLI
- Open or navigate to source files — the diff and log are the sole input
- Assume the repo is stale or offer to update it — the user is in charge

## Analyze

Answer internally before writing the report:

- What problem is this solving?
- What is the main mechanism (new feature, refactor, fix, config, tests)?
- What is out of scope or surprising?
- What could be better (correctness, clarity, tests, edge cases, scope)?
- Is there a simpler or safer design?

## Report format

Keep the report concise. Use this structure:

```markdown
## Purpose
[1–3 sentences: what this PR/MR does and why, inferred from the code]

## What changed
- [High-level bullets: areas touched and behavior added/removed — not a file list dump]

## What to improve
- [Concrete, actionable items; prefix severity when useful: **must fix** / **should fix** / **nice to have**]
- [Omit section or write "None noted" if clean]

## Would I do it differently?
- [Specific alternative only if there is a meaningful tradeoff; otherwise "No — approach is reasonable"]
```

## Rules

- Lead with purpose, not process.
- Do not restate the full diff; synthesize.
- Separate facts (what the code does) from opinions (improvements, alternatives).
- If the user pasted MR title/description, treat it as optional context only; the diff wins.
- Do not propose drive-by refactors outside the PR scope unless they block correctness.
- Expand a section only when the user asks (e.g. "more detail on improvements").
