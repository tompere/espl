#!/usr/bin/env python

import sys

gradesFile = open(sys.argv[1])

summ = 0
count = 0
gradeCounts = {}
testNumbers = {}
for line in gradesFile:
  try:
    tokens = line.strip().split(',')
    summ+= float(tokens[2])
    count+= 1
    gradeCounts[tokens[2]] += 1
  except KeyError: 
    gradeCounts[tokens[2]] = 1,
  except ValueError: pass

print "Average is " + str(summ/count)

for grade in gradeCounts.items():
  print "For grade %s, number of students is %s" % grade