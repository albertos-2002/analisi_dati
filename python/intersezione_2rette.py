def intersezione_2rette(int1, err_int1, pend1, err_pend1, cov1, int2, err_int2, pend2, err_pend2, cov2):
  import math

  x_intersezione = 0 
  err_x_intersezione = 0

  #calcolo intersezione
  x_intersezione = (int2 - int1) / (pend1 - pend2)

  #calcolo errore
  dummy1 = 0
  dummy2 = 0
  dummy3 = 0
  dummy4 = 0
  dummy5 = 0
  dummy6 = 0

  dummy1 = ( err_pend1 / (pend1 - pend2) )**2
  dummy2 = ( err_pend2 / (pend1 - pend2) )**2
  dummy3 = ( err_int2 * ( (int2 - int1) / (pend1 - pend2)**2 ) )**2
  dummy4 = ( err_pend1* ( ( int2 - int1 ) / ( pend1 - pend2 )**2 ) )**2
  dummy5 = cov1*err_pend1*err_int1
  dummy6 = cov2*err_pend2*err_int2

  err_x_intersezione = math.sqrt( (dummy1 + dummy2 + dummy3 + dummy4 + dummy5 + dummy6) )

  #print dei risultati
  print("---------------------------------------------")
  print("x intersezione")
  print(x_intersezione)
  print("incertezza")
  print(err_x_intersezione)
  print("---------------------------------------------")
