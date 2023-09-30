/*
Last Stone Weight
We have a collection of 'N' stones, each stone has a positive integer weight.

On each turn, we choose the two heaviest stones and smash them together. Suppose the stones have weights 'x' and 'y' with 'x' <= 'y'. The result of this smash will be:

1. If 'x' == 'y', both stones are totally destroyed; 2. If 'x' != 'y', the stone of weight 'x' is totally destroyed, and the stone of weight 'y' has a new weight equal to 'y - x'.

In the end, there is at most 1 stone left. Return the weight of this stone or 0 if there are no stones left.

Input format:

The first line of input contains the integer 'N', representing the total number of stones. The second line of input contains 'N' single space-separated integers, representing the weights of the stones.


Output Format:

The only output line prints the weight of the last stone, if it exists, 0 otherwise.
Note:

You do not need to print anything; it has already been taken care of. Just implement the given functions.
Constraints :
1 <= N <= 10^5 1 <= W <= 10^6 Time Limit: 1 sec
*/
import java.util.PriorityQueue;

public class StonesSmash {
    public int lastStoneWeight(int[] stones) {
        // Create a max-heap (PriorityQueue) to store stone weights in descending order
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a, b) -> b - a);

        // Add all stone weights to the max-heap
        for (int stone : stones) {
            maxHeap.offer(stone);
        }

        // Perform the smashing until there is only one stone left
        while (maxHeap.size() > 1) {
            int x = maxHeap.poll(); // Get the heaviest stone
            int y = maxHeap.poll(); // Get the second heaviest stone

            if (x != y) {
                maxHeap.offer(Math.abs(x - y)); // Add the new stone weight after smashing
            }
        }

        // Check if there is a stone left and return its weight, or return 0 if none is left
        return maxHeap.isEmpty() ? 0 : maxHeap.peek();
    }

    public static void main(String[] args) {
        StonesSmash solution = new StonesSmash();
        int[] stones = {2, 7, 4, 1, 8, 1};
        int lastStone = solution.lastStoneWeight(stones);
        System.out.println("Weight of the last stone: " + lastStone);
    }
}
