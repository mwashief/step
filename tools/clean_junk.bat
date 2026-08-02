FOR /d /r . %%d IN (META-INF) DO @IF EXIST "%%d" rd /s /q "%%d"
del /s /q *.out *.exe *.class *.jar tempCodeRunnerFile.cpp
