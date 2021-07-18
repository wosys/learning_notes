# 二维曲线的最速下降
import numpy as np
import math


# 目标函数
def objectiveFunction1D(theta):
    return -math.exp(-theta[0] ** 2 - theta[1] ** 2)


# 梯度函数
def gradientFunction1D(theta):
    derivative0 = 2 * theta[0] * math.exp(-theta[0] ** 2 - theta[1] ** 2)
    derivative1 = 2 * theta[1] * math.exp(-theta[0] ** 2 - theta[1] ** 2)
    return np.array([derivative0, derivative1])

# 最速下降法：
def gradientDescent (objFun, gradFun, theta0=np.array([1,1]),learningRate=0.2, precision=1e-4, maxIteration=10000):
    i = 0
    print("初始点: {}". format(theta0))
    theta = theta0
    for i in range(maxIteration):
        gradValue = gradFun(theta)
        theta = theta - learningRate*gradValue
        # np的范数（线性代数）
        if np.linalg.norm(gradValue) < precision:
            break
        print("第{}次迭代的值为: {}".format(i+1, theta))

    print("\n{}次迭代后，局部最优解为: {}，函数值为{}。".format(i, theta, objFun(theta)))


# 测试主函数
if __name__ == "__main__":
    gradientDescent(objectiveFunction1D, gradientFunction1D, np.array([1, 1]))
    pass


