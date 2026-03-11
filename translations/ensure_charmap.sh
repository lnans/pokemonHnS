#!/usr/bin/env bash
set -euo pipefail

# Replaces French guillemets with English curly quotes in *uncommitted* files:
#   « -> “
#   » -> ”
#
# Uncommitted = unstaged changes + staged changes + untracked files.

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(git -C "$script_dir" rev-parse --show-toplevel)"
cd "$repo_root"

script_abs="$script_dir/$(basename "${BASH_SOURCE[0]}")"

paths_tmp="$(mktemp)"
{
  git diff --name-only -z
  git diff --name-only --cached -z
  git ls-files --others --exclude-standard -z
} >"$paths_tmp"

total_left=0
total_right=0
total=0

while IFS= read -r -d '' path; do
  [[ -n "${path:-}" ]] || continue

  # Exclude this script itself from processing.
  if [[ "$repo_root/$path" == "$script_abs" ]]; then
    continue
  fi

  [[ -f "$path" ]] || continue

  # Skip binary files (grep -I treats binary as non-matching).
  if ! grep -Iq . "$path" 2>/dev/null; then
    continue
  fi

  # Count occurrences to report replacements.
  left_count=$(LC_ALL=C grep -o "«" "$path" 2>/dev/null | wc -l | tr -d ' ')
  right_count=$(LC_ALL=C grep -o "»" "$path" 2>/dev/null | wc -l | tr -d ' ')
  file_total=$((left_count + right_count))

  if (( file_total == 0 )); then
    continue
  fi

  perl -pi -e 's/«/“/g; s/»/”/g' "$path"

  printf '%s: replaced %d ( «:%d, »:%d )\n' "$path" "$file_total" "$left_count" "$right_count"

  total_left=$((total_left + left_count))
  total_right=$((total_right + right_count))
  total=$((total + file_total))
done <"$paths_tmp"

rm -f "$paths_tmp"

printf 'Total replacements: %d ( «:%d, »:%d )\n' "$total" "$total_left" "$total_right"
