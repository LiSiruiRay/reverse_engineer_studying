Author: @Ray Li
Date: 2025-09-12
Description: Snapshot of repository structure and purpose of key folders.

## Project Structure

- `background_info/`: Course syllabi and prior background context.
- `docs/`: Learning plans and documentation (this file).
- `practice/`: Hands-on RE exercises and code samples.
- `conv_logs/`: Conversation logs capturing intent, solutions, features, PRD updates.

### Current Tree (high-level)
- `background_info/`
  - `compiler_construction.md`: Graduate compiler course syllabus
  - `cso_syllubus.json`: Computer systems organization schedule
- `practice/`
  - `practice_2_rengr`: Placeholder for exercises
- `docs/`
  - `learning_plan_RE.md`: Main RE learning plan
  - `PROJECT_STRUCTURE.md`: You are here
- `conv_logs/`
  - Populated per session with timestamped markdown logs

### Conventions
- All new files start with Author/Date/Description header (no `#` in md header lines).
- Keep writeups for projects under `practice/<project_name>/README.md`.
- When structure changes, update this doc in the same commit.
