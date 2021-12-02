from scipy import fft

def dct(x):
    X = fft.dct(x)
    return X

    
def idct(X):
    x = fft.idct(X)
    return x