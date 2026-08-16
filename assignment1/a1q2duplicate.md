# assignment 1 question 2 
##  q-  Design the logic to remove the duplicate elements from an Array and after the deletion the array should contain the unique elements

## logic to remove the duplicate and delete 
# logic ( brute force approach )
1. iterate through the elements 
2. compare the elements with the one in i as we traerse through 
3. if duplicate is found then remove them from the array 

## time complexity is O ( n^2 )   
## space complexity is O ( 1)

## optimal solution 
1. create an empty hashset and traverse through array once
2. track the elements 
3. check if it already exists in the hash set 
4. if it is present then ignore it since it is a dupe
5. if it is not present keep it in the hash 
set
6. repeate till every element is checked 

## time complexity is O(n)
## space complexity is O(n)