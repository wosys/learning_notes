import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

from sklearn.linear_model import LogisticRegressionCV
from sklearn.pipeline import Pipeline
from sklearn.preprocessing import PolynomialFeatures
from sklearn.preprocessing import StandardScaler

from sklearn.metrics import mean_squared_error
from sklearn.metrics import r2_score
from math import sqrt
from datetime import datetime

def load_planar_dataset(m=1000):
    np.random.seed(12)
    # m=1000 # number of samples
    t =2 # number of type
    N= int(m/t) # number of samples per type
    D= 2 # dimensionality
    X = np.zeros((m,D))
    y = np.zeros((m, 1),dtype = 'uint8') # labels vector(0 forred, 1 for greed)
    r =6 # maxium ray of the flower
    for i in range(t):
        idx = range(N*i,N*(i+1))
        theta = np.linspace(i*3.12,(i+1)*3.12,N)+np.random.randn(N)*0.2
        radius = r*np.sin(6*theta) +np.random.randn(N)*0.2
        X[idx]=np.c_[radius*np.sin(theta),radius*np.cos(theta)]
        y[idx]=i
        #X=X.T
        # y =y.T
        return X,y
m = 700
X,y = load_planar_dataset(m=m)
df = pd. DataFrame(np.hstack((X,y)))
df.to_csv("E:/机器学习/NeualNetwork_Data1.txt", sep=",",float_format="%.7f", index=False,header=None)
df.to_csv("E:/机器学习/NeuralNetwork_Data1.csv", sep=",",
float_format="%.7f", index=False, header=["x1","x2","y"])
plt.scatter(X[:,0],X[:,1],c=y,s=30,cmap=plt.cm.Spectral)
def plot_decision_boundary (model,X,y):
    # Set min and max values and give it some padding
    x1_min, x1_max = X[:,0].min(),X[:,0].max()
    x2_min, x2_max = X[:,1].min(),X[:,1].max()
    h =0.01
    #Generate a grid of points with distance h between them
    xx, yy= np.meshgrid(np.arange(x1_min, x1_max, h), np.arange(x2_min, x2_max, h))
    #Predict the function value for the whole grid
    Z =model(np.c_[xx.ravel(),yy.ravel()])
    Z= Z.reshape(xx.shape)
    # Plot the contour and training examples
    plt.contourf(xx,yy,Z,cmap=plt.cm.Spectral)
    plt.ylabel('x2')
    plt.xlabel('x1')
    plt.scatter(X[:, 0],X[:,1],c=y,cmap=plt.cm.Spectral)
# 定义结构
def neural_network_layer_sizes(X,Y):
    '''
    Arguments :
        X -- input dataset of shape(feature size, number of exampls )
        y -- labels of shape (output size, number of examples)
        Returns:
            n_ _x -- The size of input layer
            n_ _h -- The size of hidden layer
            n_ y -- The size of output layer
    '''
    n_x = X.shape[0]
    n_h=4
    n_y = Y.shape[0]
    return (n_x, n_h, n_y)

#初始化参数
def initialize_parameters(n_x,n_h, n_y):
    '''
    Argument:
        n_x -- The size of input layer
        n_h -- The size of hidden layer
        n_y -- The size of output layer
    Returns:
        w1 -- weight matrix for layer 1 of shape (n_h,n_x)
        b1 -- bias vetor for layer 1 of shape(n_h,1)
        w2-- weighit metrix for layer 2 of shape (n_y,n_h)
        b2 -- bias vetor for layer 2 of shape(n_y,1)
        '''
    np.random.seed(12)
    W1 =np.random.randn(n_h, n_x)*0.01
    b1 =np.zeros((n_h,1))
    W2 =np.random.randn(n_y, n_h)*0.01
    b2 = np. zeros((n_y,1))
    assert(W1. shape == (n_h, n_x))
    assert(b1.shape == (n_h,1))
    assert(W2.shape == (n_y, n_h))
    assert(b2.shape == (n_y,1))
    parameters={"W1":W1, "b1":b1, "W2":W2, "b2":b2}
    return parameters

#正向预测
def sigmoid(Z):
    return 1/(1+np.exp(-Z))
def ReLU(Z):
    return np.maximum(0,Z)
def forward_propagation(X,parameters):
    """
    Arguments:
        X-- input data of size (n_x,m)
        parameters -- python dictionary containing the initialize parameters
    Returns:
        A2 -- The sigmoid output of the second activation
        cache -- a dictionary containing "Z1","A1","Z2" and "A2"
    """
    W1 = parameters["W1"]
    b1 =parameters["b1"]
    W2=parameters["W2"]
    b2 = parameters["b2"]
    #FP
    Z1 =np.dot(W1,X)+ b1
    #A1 =np.tanh(z1)
    A1 =ReLU(Z1)
    Z2 = np.dot(W2,A1)+b2
    A2 = sigmoid(Z2)
    assert(A2.shape == (b2.shape[0],X.shape[1]))
    cache = {"Z1":Z1,"A1": A1,"Z2":Z2,"A2":A2}
    return A2,cache
#成本函数
def J(A2,y,parameters):
    m=y.shape[1]
    cost = -1/m*np.sum(y*np. log(A2)+(1-y)*np.log(1-A2))
    cost = np.squeeze(cost)
    assert(isinstance(cost,float))
    return cost
#反向计算导数
def backward_propagation(X, y,parameters, cache):
    """
    Arguments:
        X-- input data of size (n_x,m)
        y -- "true" label vector of shape(n_y,m)
        parameters -- python dictionary containing the initialize parameters
        cache -- a dictionary containing "Z1", "A1", "z2" and "A2"
    Returns:
        grads -- python dictonary containing the gradients with respect to different parameters
    """
    m= X.shape[1] #number of samples
    W1 = parameters["W1"]
    W2 = parameters["W2"]
    A1 =cache["A1"]
    A2 =cache["A2"]
    #BP
    dZ2 =A2 -y
    dW2 = 1/m * np.dot(dZ2,A1.T)
    db2=1 /m * np.sum(dZ2,axis=1, keepdims=True)
    dZ1 = np.dot(W2.T,dZ2)*(1-np.power(A1,2))
    dW1 =1/m * np.dot(dZ1,X.T)
    db1 = 1 /m* np.sum(dZ1, axis=1, keepdims=True)
    #return
    grads = {"dW1": dW1,"db1": db1,"dW2": dW2,"db2": db2}
    return grads
#更新参数
def update_parameters(parameters, grads,learning_rate = 1.2):
    """
    Updates parameters using the gradient descent update rule given above
    Arguments:
        parameters -- python dictionary containing your parametersgrads -- python dictionary containing your gradients
        Returns:
            parameters -- python dictionary containing your updatedparameters
    """
    #old paremeters
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    #gradient values
    dW1 = grads ["dW1"]
    db1 = grads ["db1"]
    dW2 = grads ["dW2"]
    db2 = grads [ "db2"]
    #update parameters
    W1 =W1 - learning_rate * dW1
    b1= b1 - learning_rate * db1
    W2= W2 - learning_rate * dW2
    b2= b2 - learning_rate * db2
    #return
    parameters = {"W1": W1,"b1": b1,"W2": W2,"b2": b2}
    return parameters
def neural_network_model(X,y,n_h,learning_rate = 0.9,max_iterations = 10000,err_torlance = 1e-12,print_cost = False):
    """
    Arguments:
        X -- dataset of shape (2, number of examples)
        y -- labels of shape（1,number of examples)
        n_h -- size of the hidden layer
        num_iterations -- Number of iterations in gradient descent loop
        print_cost -- if True,print the cost every 100e iterations
        Returns:
        parameters -- parameters learnt by the model and then can beused to predict.
    """
    tic = datetime.now()
    np.random.seed(12)
    # layer of neural network
    n_X =neural_network_layer_sizes(X,y)[0]
    n_y = neural_network_layer_sizes(X,y)[2]
    #initialize parameters
    parameters = initialize_parameters(n_X, n_h, n_y)
    W1 = parameters["W1"]
    b1 = parameters["b1"]
    W2 = parameters["W2"]
    b2 = parameters["b2"]
    cost_value_list = list(np.zeros((max_iterations, 1)))
    last_cost =0
    # loop (using gradient descent)
    for i in range(max_iterations):
        #1. Forward Propogation
        A2,cache = forward_propagation(X,parameters)
        #2.Compute cost Function
        cost = J(A2,y,parameters)
        #3. Backward Propogation
        grads = backward_propagation(X, y, parameters, cache)
        #4. Update Parameters
        parameters = update_parameters(parameters,grads,learning_rate=learning_rate)
        #5.Print cost Values
        if print_cost and i % 1000 == 0:
            print("\n====================")
            print( "cost value after iteration {:d}:{:f}".format(i, cost))
        #6. Exit Control
        cost_value_list[i] = cost
        if np.abs(cost-last_cost) < err_torlance:
            cost_value_list = cost_value_list[0:i]
            break
        last_cost = cost
    toc=datetime.now()
    delta=toc-tic
    return parameters,cost_value_list,delta.total_seconds()
'''def nn_model_test(learning_rate=1.2):
    parameters,cost_list = neural_network_model(X.T,y.T, n_h=4,
    learning_rate=learning_rate,max_iterations=10000,err_torlance= 1e-12,print_cost=True)
    print("W1 =" + str(parameters["W1"]))
    print("b1 =" + str(parameters["b1"]))
    print("W2 =" + str(parameters["W2"]))
    print("b2 =" + str(parameters[ "b2"]))
    plt.plot(range(len(cost_list)),cost_list)
nn_model_test(2.1)'''
def predict(X,parameters):
    A2,cache = forward_propagation(X, parameters)
    predictions =np.array (A2>=0.5,dtype=int)
    return predictions
def predict_test_case():
    np.random.seed(12)
    X_test = np.random.randn(2,3)
    parameters = { 'W1':np.array([[-0.00615039,0.0169021 ],
                                  [-0.02311792,0.03137121],
                                  [ -0.0169217,-0.01752545],
                                  [0.00935436,-0.05018221]]),
                  'W2': np.array([[-0.0104319 , -0.04019007,0.01607211,0.04440255]]),
                  'b1':np.array([[ -8.97523455e-07],
                  [8.15562092e-06],
                  [6.04810633e-07],
                  [-2.54560700e-06]]),
                  'b2':np.array([[ 9.14954378e-05]])}
    return X_test,parameters
X_test,parameters_test=predict_test_case()
predictions=predict(X_test, parameters_test)
print("Predict mean:{:f}".format(np.mean(predictions)))
parameters, cost_list, training_time = neural_network_model(X.T,y.T, n_h=17, learning_rate=5.2,max_iterations=10000,
err_torlance = 1e-12,print_cost = False)
plot_decision_boundary(lambda x:predict(x.T, parameters), X, y)
plt.title("Neural Network Classfication")
plt.scatter(X[:,0],X[:,1],c=y)
y_predict = predict(X.T,parameters)
rmse_score = sqrt(mean_squared_error(y.T, y_predict))
accuracy_score = np.sum(np.array(y.T==y_predict, dtype=int)) / len(y)
print("所有数据集上得分:{:.7f} --{:.7f}，耗时{:f}秒! ".format(rmse_score,accuracy_score,training_time))

plt.figure(figsize=(16,32))
hidden_layer_sizes =[1,2,3,4,5,7,10,15,20,50,78,99]
for i, n_h in enumerate(hidden_layer_sizes):
    #决策边界
    plt.subplot(len(hidden_layer_sizes), 2,i*2+1)
    plt.title('The size Hidden Layer: %d'% n_h)
    parameters, cost_list, training_time = neural_network_model(X.T, y.T, n_h=n_h, learning_rate=0.9,max_iterations=10000,err_torlance = 1e-12,print_cost = False)
    plot_decision_boundary(lambda x:predict(x.T, parameters),X,y)
    plt.scatter(X[:, 0],X[:,1],c=y)
    #函数值
    plt.subplot(len(hidden_layer_sizes), 2,i*2+2)
    plt.title('The Cost Function value descent')
    plt.plot(range(len(cost_list)), cost_list)
    y_predict = predict(X.T, parameters)
    rmse_score = sqrt(mean_squared_error(y.T, y_predict))
    accuracy_score = np. sum(np. array(y.T==y_predict, dtype=int)) /len(y)
    print("模型(Hidden Units = {:d}) 得分: {:.7f}--{:.7f},耗时{:f}秒!".format(n_h, rmse_score, accuracy_score, training_time))









