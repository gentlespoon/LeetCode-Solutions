# GentleSpoon me@gentlespoon.com
# Leetcode    Q175
# Start       2017-11-07-14-40-42
# Finish      2017-11-07-14-40-43

# Table: Person
#
# +-------------+---------+
# | Column Name | Type    |
# +-------------+---------+
# | PersonId    | int     |
# | FirstName   | varchar |
# | LastName    | varchar |
# +-------------+---------+
# PersonId is the primary key column for this table.
# Table: Address
# 
# +-------------+---------+
# | Column Name | Type    |
# +-------------+---------+
# | AddressId   | int     |
# | PersonId    | int     |
# | City        | varchar |
# | State       | varchar |
# +-------------+---------+
# AddressId is the primary key column for this table.
# 
# Write your MySQL query statement below


SELECT FirstName, LastName, City, State FROM Person LEFT JOIN Address ON Person.PersonId=Address.PersonId