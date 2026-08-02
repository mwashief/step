OUTPUT=$(python3 ./${1:-codeforces}.py vim)
LAST_LINE=$(echo "$OUTPUT" | tail -n1)
echo "${OUTPUT}"  | sed '$d'
vim ${LAST_LINE}
