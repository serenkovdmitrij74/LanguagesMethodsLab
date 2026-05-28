import numpy as np
import matplotlib.pyplot as plt

def fill_mis(matrix):
    filled_matrix = np.copy(matrix)
    
    num_rows, num_cols = filled_matrix.shape
    
    for r in range(0, num_rows):
        for c in range(0, num_cols):
            if filled_matrix[r, c] == 999.9:
                if r>0:
                    prev_year_val = filled_matrix[r - 1, c]
                else:
                    prev_year_val= filled_matrix[r + 1, c]
                
                if r+1<num_rows and filled_matrix[r + 1, c]!=999.9:
                    next_year_val = filled_matrix[r + 1, c]
                else:
                    next_year_val= prev_year_val
                
                average_val = (prev_year_val + next_year_val) / 2.0
                filled_matrix[r, c] = np.round(average_val, 1)       
    return filled_matrix

def mse(y_true, y_pred):
    return np.sum((y_true - y_pred)**2)/len(y_pred)


def fit(X_train, Y_train, model_type):
    n = len(X_train)
    
    if model_type == 'lin':
        A = np.array([[n, np.sum(X_train)],[np.sum(X_train), np.dot(X_train, X_train)]])
        b = np.array([np.sum(Y_train), np.dot(X_train, Y_train)])
        
    elif model_type == 'quadr':
        A = np.array([
            [np.sum(X_train**4), np.sum(X_train**3), np.sum(X_train**2)],
            [np.sum(X_train**3), np.sum(X_train**2), np.sum(X_train)],
            [np.sum(X_train**2), np.sum(X_train), n]])
        b = np.array([np.sum(X_train**2 * Y_train), np.sum(X_train * Y_train), np.sum(Y_train)])
        
    elif model_type == 'exp':
        X_sub = X_train / 10.0
        A = np.array([
            [np.sum(np.exp(2 * X_sub)), n, np.sum(np.exp(X_sub))],
            [n, np.sum(np.exp(-2 * X_sub)), np.sum(np.exp(-1 * X_sub))],
            [np.sum(np.exp(X_sub)), np.sum(np.exp(-1 * X_sub)), n]])
        b = np.array([np.sum(np.exp(X_sub) * Y_train), np.sum(np.exp(-1 * X_sub) * Y_train), np.sum(Y_train)])
        
    return np.linalg.inv(A).dot(b)

def predict_model(X, a, model_type):
    if model_type == 'lin':
        return a[0] + a[1] * X
    elif model_type == 'quadr':
        return a[0] * X**2 + a[1] * X + a[2]
    elif model_type == 'exp':
        X_sub = X / 10.0
        return a[0] * np.exp(X_sub) + a[1] * np.exp(-1 * X_sub) + a[2]

data = np.loadtxt('LabMiMiMi/lab1/Weather.csv', delimiter = ',')
Y = data[:, 0]
X = fill_mis(data[:, 1:13] )


Y_scaled = (Y - Y.min()) / (Y.max() - Y.min())


indices = np.arange(len(Y))
np.random.shuffle(indices)
train_size = int(0.75 * len(Y))
train_idx = indices[:train_size]
test_idx = indices[train_size:]

month_names = ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"]


fig, axes = plt.subplots(4, 3, figsize=(18, 16))
axes = axes.flatten()

for i in range(12):
    y_all = X[:, i]
    y_train = y_all[train_idx]
    y_test = y_all[test_idx]
    
    beta_lin = fit(Y_scaled[train_idx], y_train, 'lin')
    beta_quad = fit(Y_scaled[train_idx], y_train, 'quadr')
    beta_exp = fit(Y_scaled[train_idx], y_train, 'exp')
    
    pred_lin_all = predict_model(Y_scaled, beta_lin, 'lin')
    pred_quad_all = predict_model(Y_scaled, beta_quad, 'quadr')
    pred_exp_all = predict_model(Y_scaled, beta_exp, 'exp')
    
    mse_lin = mse(y_test, pred_lin_all[test_idx])
    mse_quad = mse(y_test, pred_quad_all[test_idx])
    mse_exp = mse(y_test, pred_exp_all[test_idx])
    
    results = {'Линейная': mse_lin, 'Квадратичная': mse_quad, 'Экспонента': mse_exp}
    best_model = min(results, key=results.get)
    
    ax = axes[i]
    ax.scatter(Y[train_idx], y_train, color='gray', alpha=0.6, s=15)
    ax.scatter(Y[test_idx], y_test, color='red', alpha=0.8, s=20)
    
    sort_idx = np.argsort(Y)
    ax.plot(Y[sort_idx], pred_lin_all[sort_idx], linestyle='--')
    ax.plot(Y[sort_idx], pred_quad_all[sort_idx], linestyle='-.')
    ax.plot(Y[sort_idx], pred_exp_all[sort_idx], linestyle=':')
    
    ax.set_title(f'{month_names[i]}\nЛучшая: {best_model}')

plt.tight_layout()
plt.show()
