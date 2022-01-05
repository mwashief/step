import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;

public class Codeforces {
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";
    public static int bundleSize = 250;

    public static String getBundle(String contest)
    {
        int bundleNumber = (Integer.parseInt(contest) + bundleSize - 1) / bundleSize;
        int end = bundleSize * bundleNumber;
        int start = end - bundleSize + 1;
        String startBundle = new StringBuilder(String.valueOf(start)).reverse().toString();
        String endBundle = new StringBuilder(String.valueOf(end)).reverse().toString();
        while(startBundle.length() < 4) startBundle = startBundle + "0";
        while(endBundle.length() < 4) endBundle = endBundle + "0";
        startBundle = new StringBuilder(startBundle).reverse().toString();
        endBundle = new StringBuilder(endBundle).reverse().toString();
        return startBundle + "-" + endBundle;
    }

    public static void main(String[] args) throws Exception {
        String problemID;
        Scanner sc = new Scanner(System.in);
        if(args.length == 0)
            problemID = sc.nextLine();
        else problemID = args[0];
        sc.close();

        problemID = problemID.toUpperCase();
        String contest = "";
        String problem = "";
        for (int i = 0; i < problemID.length(); i++) {
            if (problemID.charAt(i) >= '0' && problemID.charAt(i) <= '9')
                contest = contest + problemID.charAt(i);
            else {
                problem = problemID.substring(i, problemID.length());
                break;
            }
        }
        if (contest.length() == 0) {
            System.out.println(ANSI_RED + "Invalid contest!" + ANSI_RESET);
            return;
        }
        if (problem.length() == 0) {
            System.out.println(ANSI_RED + "Problem no is not provided!" + ANSI_RESET);
            return;
        }
        System.out.println(ANSI_GREEN + "Contest: " + contest + " Problem : " + problem + ANSI_RESET);
        String dir = System.getProperty("user.dir") + "/Codeforces/" + getBundle(contest) + "/" + contest ;

        if (Files.isDirectory(Paths.get(dir)))
            System.out.println(ANSI_BLUE + contest + " contest folder already exists." + ANSI_RESET);
        else {
            System.out.println(ANSI_YELLOW + contest + " contest folder does not exist." + ANSI_RESET);
            Files.createDirectories(Paths.get(dir));
            System.out.println(ANSI_CYAN + contest + " contest folder created." + ANSI_RESET);
        }

        dir = dir + "/" + problemID + ".cpp";

        if (Files.exists(Paths.get(dir)))
            System.out.println(ANSI_BLUE + problemID + ".cpp already exists." + ANSI_RESET);
        else {
            Files.createFile(Paths.get(dir));
            System.out.println(ANSI_CYAN + problemID + ".cpp created." + ANSI_RESET);
        }
        String os = System.getProperty("os.name");

        if(args.length > 0){
            System.out.println(dir);
            return;
        }

        String[] fargs = new String[] { "cmd.exe", "/c", "code", dir };
        if (os.equalsIgnoreCase("Linux"))
            fargs = new String[] { fargs[2], fargs[3] };

        new ProcessBuilder(fargs).start();
    }
}
