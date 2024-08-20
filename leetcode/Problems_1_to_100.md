# LeetCode Problems 1 to 100

The repo contains the description of problems from 1 to 100, along with solutions.

## List of Problems (1 - 100)

| Number | Title                                                                          | Difficulty | Code                                                   | LC Website  | Video Solution |
| ------ | ------------------------------------------------------------------------------ | ---------- | ------------------------------------------------------ | ----------- | -------------- |
| 49     | [Group Anagrams](#49-group-anagrams)                                           | Medium     | [Solution](49.Group_Anagrams.cpp)                      | Coming Soon | Coming Soon    |
| 26     | [Remove Duplicates_From_Sorted_Array](#26-remove-duplicates-from-sorted-array) | Easy       | [Solution](26.Remove_Duplicates_from_Sorted_Array.cpp) | Coming Soon | Coming Soon    |

---

---

---

## Problem Solutions

### 49. Group Anagrams

**Difficulty:** Medium  
**Topics:** Hash Table, String, Sorting  
**Companies:** Amazon, Facebook, Google

### Problem Description

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Examples

**Example 1:**

```text
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```text
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```text
Input: strs = ["a"]
Output: [["a"]]
```

### Constraints

- `1 <= strs.length <= 10^4`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

**[View the Solution](49.Group_Anagrams.cpp)**

---

### 93. Restore IP Addresses

**Difficulty:** Medium  
**Topics:** String, Backtracking  
**Companies:** Amazon, Google

### Problem Description

A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, `"0.1.2.201"` and `"192.168.1.1"` are valid IP addresses, but `"0.011.255.245"`, `"192.168.1.312"` and `"192.168@1.1"` are invalid IP addresses.

Given a string `s` containing only digits, return all possible valid IP addresses that can be formed by inserting dots into `s`. You are not allowed to reorder or remove any digits in `s`. You may return the valid IP addresses in any order.

### Examples

**Example 1:**

```text
Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
```

**Example 2:**

```text
Input: s = "0000"
Output: ["0.0.0.0"]
```

**Example 3:**

```text
Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
```

### Constraints

- `1 <= s.length <= 20`
- `s` consists of digits only.

**[View the Solution](93.Restore_IP_Addresses.cpp)**
