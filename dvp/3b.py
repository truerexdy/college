#3b
import difflib as dl
s1 = input("Enter string 1")
s2 = input("Enter string 2")
match = dl.SequenceMatcher(None, s1, s2)
print(f"Similarity = {match.ratio()}")