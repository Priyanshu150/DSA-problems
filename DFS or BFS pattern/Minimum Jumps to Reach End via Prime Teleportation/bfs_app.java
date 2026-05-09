import java.util.*

// Time complexity :- O(n*log(log(n)) + n)
// Space complexity :- O(n)

// Approach :-  
// calculate all prime number till max number present in the array 
// use bfs approach to explore the shortest path to reach the end of array 
// try exploring (i+1), (i-1) and multiple of the primes numbers 

// Links :- https://www.geeksforgeeks.org/problems/check-if-subtree/1

class Solution {
    private boolean[] isPrime;

    private void buildSieve(int maxEle){
        isPrime = new boolean[maxEle + 1];
        Arrays.fill(isPrime, true);

        if(maxEle >= 0) isPrime[0] = false;
        if(maxEle >= 1) isPrime[1] = false;

        for(int num=2; num*num <= maxEle; ++num){
            if(isPrime[num]){
                for(int multiple = num*num; multiple <= maxEle; multiple += num){
                    isPrime[multiple] = false;
                }
            }
        }
    }

    public int minJumps(int[] nums) {
        int n = nums.length;
        HashMap<Integer, List<Integer>> mp = new HashMap<>();

        int maxEle = 0;

        for(int i=0; i<n; ++i){
            maxEle = Math.max(maxEle, nums[i]);
            mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }
        buildSieve(maxEle);

        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];

        queue.offer(0);
        visited[0] = true;

        HashSet<Integer> seen = new HashSet<>();
        int steps = 0;

        while(!queue.isEmpty()){
            int size = queue.size();

            while(size-- > 0){
                int i = queue.poll();

                if(i == n - 1) {
                    return steps;
                }

                // i - 1
                if(i - 1 >= 0 && !visited[i - 1]) {

                    queue.offer(i - 1);
                    visited[i - 1] = true;
                }

                // i + 1
                if(i + 1 < n && !visited[i + 1]) {

                    queue.offer(i + 1);
                    visited[i + 1] = true;
                }

                // skip if not prime or already processed
                if(!isPrime[nums[i]] || seen.contains(nums[i])) {
                    continue;
                }

                // visit all multiples
                for(int multiple = nums[i];
                    multiple <= maxEle;
                    multiple += nums[i]) {

                    if(!mp.containsKey(multiple)) {
                        continue;
                    }

                    for(int j : mp.get(multiple)) {

                        if(!visited[j]) {

                            queue.offer(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.add(nums[i]);
            }
            ++steps;
        }
        return steps;
    }
}