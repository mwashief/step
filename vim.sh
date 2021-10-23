OUTPUT=$(java ./${1:-Codeforces}.java vim)
LAST_LINE=$(echo "$OUTPUT" | tail -n1)
echo "${OUTPUT}"  | sed '$d'
vim ${LAST_LINE}