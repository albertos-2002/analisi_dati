def retta_fit_xba(x, b,a):
  y = []
  for i in range(len(x)):
    dummy = 0
    dummy = (x[i]*b) + a
    y.append(dummy)
  return y

def retta_fit_xa(x, a):
  y = []
  for i in range(len(x)):
    dummy = 0
    dummy = (x[i]*0) + a
    y.append(dummy)
  return y
