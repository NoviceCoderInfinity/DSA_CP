#!/bin/bash

# Change to leetcode directory
cd leetcode

echo ""
echo "📂 Entered leetcode directory"
echo ""

# Check for untracked files
untracked_files=$(git ls-files --others --exclude-standard | grep '\.cpp$')
# Check for modified files
modified_files=$(git ls-files -m | grep '\.cpp')


# Nothing to commit
if [ -z "$untracked_files" ] && [ -z "$modified_files" ]; then
	echo "✅ No new or modified files to commit."
	exit 0
fi


# Commit untracked files
for file in $untracked_files; do
	problem_no=$(echo "$file" | cut -d. -f1)

	echo "➕ Adding new file: $file (Problem $problem_no)"

	git add "$file"
	git commit -m "Added Solution for LeetCode Problem $problem_no"
	git push -u origin main
	echo ""
	echo ""
done


# Commit tracked files
for file in $modified_files; do
	if echo "$untracked_files" | grep -q "^$file$"; then
		continue
	fi
	problem_no=$(echo "file" | cut -d. -f1)
	echo "♻️  Committing update to file: $file (Problem $problem_no)"
	git add "$file"
	git commit -m "Added new approach for LeetCode Problem $problem_no"
	git push -u origin main
done

echo ""
echo "✅ All done!"
echo ""
