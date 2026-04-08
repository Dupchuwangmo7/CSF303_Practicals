
## 1. Nearly Lucky Number

### Problem
Determine if a number is "nearly lucky" - having a count of lucky digits (4 and 7) that is itself a lucky number.

### Algorithm
Direct counting approach

### Complexity
- **Time:** O(n) where n = number of digits
- **Space:** O(1)

### Key Points
- Counts digits 4 and 7 in input
- Validates if count contains only 4s and 7s
- Handles large numbers up to 10^18 using string input


## 2. Girl or Boy

### Problem
Determine gender based on the number of unique characters in a username string. If unique characters count is even, output "CHAT WITH HER!", otherwise "IGNORE HIM!".

### Algorithm
Set-based unique character counting

### Complexity
- **Time:** O(n log m) where n = string length, m = unique characters (≤ 26)
- **Space:** O(m) for the set

### Key Points
- Uses `set<char>` to store unique characters
- Checks if set size is even or odd
- Efficient for small alphabets (≤ 26 chars)


## 3. Magic Numbers

### Problem
Check if a string can be completely decomposed into patterns "144", "14", or "1" (in that order of preference).

### Algorithm
Greedy string matching with pattern priority

### Complexity
- **Time:** O(n) where n = string length
- **Space:** O(1) for constant variables

### Key Points
- Greedy approach: tries longest pattern first
- Single pass through string
- Each character processed at most once
- No backtracking required
- Valid patterns: "144" → skip 3 chars, "14" → skip 2 chars, "1" → skip 1 char
- Invalid if any character doesn't match patterns


## 4. Dima and Friends

### Problem
Count number of ways Dima (with 1-5 fingers) can choose such that he is not in position 1 (modulo n+1, where n is number of friends).

### Algorithm
Brute force enumeration

### Complexity
- **Time:** O(n) for summing friends' fingers + O(5) for Dima's choices = **O(n)**
- **Space:** O(1) for constant variables

### Key Points
- Sums all friends' finger counts
- Tries all 5 possible finger values for Dima (1 to 5)
- For each value, calculates position as (sum + value) % (n+1)
- Counts valid configurations where position ≠ 1
- Constant 5 iterations makes this effectively linear in n


