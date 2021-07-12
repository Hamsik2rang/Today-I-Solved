import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static boolean check[];

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer>[] graph = new ArrayList[1001];
        for (int i = 0; i < 1001; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        int n, m, v;

        n = sc.nextInt();
        m = sc.nextInt();
        v = sc.nextInt();

        for (int i = 0; i < m; i++) {
            int from, to;
            from = sc.nextInt();
            to = sc.nextInt();

            graph[from].add(to);
            graph[to].add(from);
        }
        // 더 작은 정점 번호부터 방문하기 위한 정렬
        for (int i = 0; i < graph.length; i++) {
            Collections.sort(graph[i]);
        }
        check = new boolean[1001];
        dfs(v, graph);
        System.out.println();
        check = new boolean[1001];
        bfs(v, graph);
    }

    public static void dfs(int x, ArrayList<Integer>[] graph) {

        check[x] = true;
        System.out.print(x + " ");
        for (int i = 0; i < graph[x].size(); i++) {
            int next = graph[x].get(i);
            if (!check[next]) {
                dfs(next, graph);
            }
        }
    }

    public static void bfs(int x, ArrayList<Integer>[] graph) {
        final boolean check[] = new boolean[1001];
        Queue<Integer> q = new LinkedList<Integer>();

        check[x] = true;
        q.add(x);
        System.out.print(x + " ");

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i = 0; i < graph[cur].size(); i++) {
                int next = graph[cur].get(i);
                if (!check[next]) {
                    check[next] = true;
                    System.out.print(next + " ");
                    q.add(next);
                }
            }
        }
    }
}