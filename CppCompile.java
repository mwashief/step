public class CppCompile {
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";
    public static final String ANSI_BLACK_BACKGROUND = "\u001B[40m";
    public static final String ANSI_RED_BACKGROUND = "\u001B[41m";
    public static final String ANSI_GREEN_BACKGROUND = "\u001B[42m";
    public static final String ANSI_YELLOW_BACKGROUND = "\u001B[43m";
    public static final String ANSI_BLUE_BACKGROUND = "\u001B[44m";
    public static final String ANSI_PURPLE_BACKGROUND = "\u001B[45m";
    public static final String ANSI_CYAN_BACKGROUND = "\u001B[46m";
    public static final String ANSI_WHITE_BACKGROUND = "\u001B[47m";

    public static void main(String[] args) throws Exception {
        if (args.length == 0)
            return;
        String path = args[0];
        path = path.replace("\"", "");
        String extension = "";
        if (path.contains("."))
            extension = path.substring(path.lastIndexOf(".") + 1);
        String os = System.getProperty("os.name");
        if (os.equalsIgnoreCase("Linux")) {
            System.out.println(ANSI_PURPLE + "OS: " + ANSI_RESET + ANSI_BLUE + "Linux" + ANSI_RESET);
            System.out.println(ANSI_PURPLE + "Path: " + ANSI_RESET + ANSI_BLUE + path + ANSI_RESET);
            String file = "";
            if (path.contains("/")) {
                if (path.contains(".") && path.lastIndexOf("/") < path.lastIndexOf("."))
                    file = path.substring(path.lastIndexOf("/") + 1, path.lastIndexOf("."));
                else
                    file = path.substring(path.lastIndexOf("/") + 1);
                path = path.substring(0, path.lastIndexOf("/"));
            } else {
                if (path.contains("."))
                    file = path.substring(0, path.lastIndexOf("."));
                else
                    file = path;
                path = "";
            }

            String[] fargs = new String[] { "g++", "-std=c++17",
                    "-DLOCAL_OUTPUT=\"" + System.getProperty("user.dir") + "/IO/output.dat\"",
                    "-DLOCAL_INPUT=\"" + System.getProperty("user.dir") + "/IO/input.dat\"",
                    path + "/" + file + "." + extension, "-o", path + "/" + file + ".out" };

            new ProcessBuilder(fargs).inheritIO().start().waitFor();
            System.out.println(ANSI_GREEN + "\u2713" + ANSI_RESET + ANSI_YELLOW + " Compilation done" + ANSI_RESET);
            long startTime = System.nanoTime();
            new ProcessBuilder(new String[] { path + "/" + file + ".out" }).inheritIO().start().waitFor();
            long endTime = System.nanoTime();
            long timeElapsed = endTime - startTime;
            System.out.println("\u2713 Execution done");
            System.out.println(ANSI_RED + "Execution time: " + ANSI_RED_BACKGROUND + ANSI_BLACK + timeElapsed / 1000000
                    + "ms" + ANSI_RESET);
        } else {
            System.out.println(ANSI_PURPLE + "OS: " + ANSI_RESET + ANSI_BLUE + "Windows" + ANSI_RESET);
            System.out.println(ANSI_PURPLE + "Path: " + ANSI_RESET + ANSI_BLUE + path + ANSI_RESET);
            String file = "";
            if (path.contains("\\")) {
                if (path.contains(".") && path.lastIndexOf("\\") < path.lastIndexOf("."))
                    file = path.substring(path.lastIndexOf("\\") + 1, path.lastIndexOf("."));
                else
                    file = path.substring(path.lastIndexOf("\\") + 1);
                path = path.substring(0, path.lastIndexOf("\\"));
            } else {
                if (path.contains("."))
                    file = path.substring(0, path.lastIndexOf("."));
                else
                    file = path;
                path = "";
            }
            String dir = System.getProperty("user.dir");
            dir = dir.replace("\\", "\\\\");

            String[] fargs = new String[] { "cmd.exe", "/c", "g++", "-Wl,--stack,268435456",
                    "-DLOCAL_OUTPUT=\\\"" + dir + "\\\\IO\\\\output.dat\\\"",
                    "-DLOCAL_INPUT=\\\"" + dir + "\\\\IO\\\\input.dat\\\"",
                    "\"" + path + "\\" + file + "." + extension + "\"", "-o", "\"" + path + "\\" + file + "\"" };

            new ProcessBuilder(fargs).inheritIO().start().waitFor();
            System.out.println(ANSI_GREEN + "\u2713" + ANSI_RESET + ANSI_YELLOW + " Compilation done" + ANSI_RESET);
            long startTime = System.nanoTime();
            new ProcessBuilder(new String[] { "cmd.exe", "/c", "\"" + path + "\\" + file + "\"" }).inheritIO().start()
                    .waitFor();
            long endTime = System.nanoTime();
            long timeElapsed = endTime - startTime;
            System.out.println("\u2713 Execution done");
            System.out.println(ANSI_RED + "Execution time: " + ANSI_RED_BACKGROUND + ANSI_BLACK + timeElapsed / 1000000
                    + "ms" + ANSI_RESET);

        }

    }
}