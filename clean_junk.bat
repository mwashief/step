FOR /d /r . %%d IN (".cph") DO @IF EXIST "%%d" rd /s /q "%%d"
del /s /q *.exe *.class tempCodeRunnerFile.cpp
