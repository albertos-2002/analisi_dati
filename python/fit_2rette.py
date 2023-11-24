x_orizzontali = np.log10(  )
y_orizzontali = 
err_y_orizzontali = 

x_oblique_i = np.log10(  )
y_oblique_i = 
err_y_oblique_i = 

print("Regressione orizzontale")
print("la regressione lineare a due parametri non ha validità, inserita per avere una approssimazione di rho ed eeepost")
regrlin_pear_errpost_xys(x_orizzontali, y_orizzontali, err_y_orizzontali)
param_oz, cov_oz = curve_fit(retta_fit_xa, x_orizzontali, y_orizzontali, sigma=err_y_orizzontali)
print("-----------------")
print(param_oz)
print(cov_oz)
print("--------------------------------------------------------------------------------------")
print("Regrezzione obliqua")
regrlin_pear_errpost_xys(x_oblique_i, y_oblique_i, err_y_oblique_i)
param_oi, cov_oi = curve_fit(retta_fit_xba, x_oblique_i, y_oblique_i, sigma=err_y_oblique_i)
print("-----------------")
print(param_oi)
print(cov_oi)
print("--------------------------------------------------------------------------------------")
