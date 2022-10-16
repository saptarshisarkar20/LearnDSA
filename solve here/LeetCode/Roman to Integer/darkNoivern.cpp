class Solution {
    public int romanToInt(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int sum = map.get(s.charAt(s.length() - 1));
        for (int i = s.length() - 2; i >= 0; i--) {
            char first = s.charAt(i); 
            char second = s.charAt(i + 1);
            if (map.get(first) < map.get(second)) {
                sum -= map.get(first);
            } else {
                sum += map.get(first);
            }
        }
        return sum;
    }
}
