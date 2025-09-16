Author: @Ray Li
Date: 2025-09-12
Description: Snapshot of repository structure and purpose of key folders.

## Project Structure

- `background_info/`: Course syllabi and prior background context.
- `docs/`: Learning plans and documentation (this file).
- `practice/`: Hands-on RE exercises and code samples.
  - `practice_2_rengr_lab/`: XOR demo and lab mapping to assembly
- `conv_logs/`: Conversation logs capturing intent, solutions, features, PRD updates.
- `sample_learning/`: Example walkthroughs and annotated artifacts.

### Current Tree (high-level)
- `background_info/`
  - `compiler_construction.md`: Graduate compiler course syllabus
  - `cso_syllubus.json`: Computer systems organization schedule
- `practice/`
  - `practice_2_rengr`: Placeholder for exercises
  - `practice_2_rengr_lab/`
    - `xor_demo.c`: C demo of XOR routine
    - `README.md`: How it maps to assembly
- `docs/`
  - `learning_plan_RE.md`: Main RE learning plan
  - `PROJECT_STRUCTURE.md`: You are here
- `sample_learning/`
  - `practice_2_rengr_assembly.txt`: Original disassembly
  - `practice_2_rengr_assembly_annotated.txt`: Annotated version
- `conv_logs/`
  - Populated per session with timestamped markdown logs

### Conventions
- All new files start with Author/Date/Description header (no `#` in md header lines).
- Keep writeups for projects under `practice/<project_name>/README.md`.
- When structure changes, update this doc in the same commit.
