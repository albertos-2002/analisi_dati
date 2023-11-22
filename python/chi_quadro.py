def chi_quadro(y_vec, x_vec, sigma_vec, y_ref, stringa_ytitle, stringa_xtitle, stringa_titolo, bolean_parameter):

  import math
  import matplotlib.pyplot as plt

#La formula della retta utilizzata è: y = a + bx
#dati
  y = list(y_vec)
  x = list(x_vec)
  sigma = list(sigma_vec)
  dimensione = len(y)

#calcolo del chi quadro
  vettore_scarti_quadratici = []
  vettore_scarti = []
  for i in range(dimensione):
    dummy_2 = 0
    dummy_3 = 0
    dummy_4 = 0
    dummy_2 = y[i] - y_ref[i]
    dummy_3 = dummy_2 / sigma[i]
    dummy_4 = dummy_3**2
    vettore_scarti_quadratici.append(dummy_4)
    vettore_scarti.append(dummy_2)

  chi_quadro = sum(vettore_scarti_quadratici)
  print("chi quadro \n", chi_quadro)
  print("NDOF  \n", dimensione-2)

#print del grafico degli scarti
  ascisse = x

  plt.errorbar(ascisse, vettore_scarti, marker=".", linestyle="none", yerr=sigma, ecolor="cornflowerblue")
  if bolean_parameter == True:
    plt.xscale("log", base=10)
  plt.title("Grafico dei residui di regressione " + stringa_titolo )
  plt.ylabel(stringa_ytitle)
  plt.xlabel(stringa_xtitle)
  plt.axhline(0, color='black', linewidth="0.6")
  plt.grid()
