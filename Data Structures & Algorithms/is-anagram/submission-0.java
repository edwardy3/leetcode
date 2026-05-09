class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }
        Map<Character, Integer> first = new HashMap<>();
        Map<Character, Integer> second = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            first.put(s.charAt(i), first.getOrDefault(s.charAt(i), 0) + 1);
            second.put(t.charAt(i), second.getOrDefault(t.charAt(i), 0) + 1);
        }
        if (first.equals(second)) {
            return true;
        }
        return false;
    }
}
