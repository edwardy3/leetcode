class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> temp = new HashSet<>();
        for (int element : nums) {
            if (!temp.contains(element)) {
                temp.add(element);
            } else {
                return true;
            }
        }
        return false;
    }
}