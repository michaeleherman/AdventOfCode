h = {}
for l in open('day7Test.txt','rt').readlines():
  i, j = l[36], l[5]
  if i not in h: h[i] = []
  if j not in h: h[j] = []
  h[i].append( j )

print ("Printing length of h", len(h))

r = ''
while len(h):
  print (h.items() )

  temp = []
  for k, v in h.items():
   if len(v) == 0:
      temp.append(k)
  if len(temp) != 0:
    e = sorted(temp)[0]

  #e = sorted( k for k,v in h.items() if len(v)==0)[0]
    print (e)
    del h[e]
    for k in h:
      if e in h[k]: h[k].remove(e)
  # could be one line too: for k in h: e not in h[k] or h[k].remove(e)
    r += e
print( r )