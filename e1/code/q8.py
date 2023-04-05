import sys
print(set(sys.argv[1]).symmetric_difference(sys.argv[2]))
print(max(sys.argv[1::], key=len), len(max(sys.argv[1::], key=len)))