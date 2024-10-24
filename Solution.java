import java.util.Stack;

public class Solution {
    public String removeDuplicates(String s) {
    
        Stack<Character> stack = new Stack<>();
        
        
        for (char c : s.toCharArray()) {
        
            if (!stack.isEmpty() && stack.peek() == c) {
            
                stack.pop();
            } else {
            
                stack.push(c);
            }
        }
        
    
        StringBuilder result = new StringBuilder();
        for (char c : stack) {
            result.append(c);
        }
        
        return result.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution(); 
        String s = "abbaca"; 
        System.out.println("Final string after duplicates removal: " + solution.removeDuplicates(s));
    }
}