find . ! -path "*/.git/*" \( -name '*.class' -or -name '*.prob' -or -name '*.exe' -or ! -name "*.*" -or -name "tempCodeRunnerFile.cpp" \) -type f -delete
