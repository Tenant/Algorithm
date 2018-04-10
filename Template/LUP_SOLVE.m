function x=LUP_SOLVE(L, U, P, b)
    % function x=LUP_SOLVE(L, U, P, b)
    %
    % 通过LUP分解求解线性方程组Ax=b, 其中A为非奇异矩阵
    % 算法总体时间复杂度为n^2，具有数值稳定性
    % PA=LU, A=P^-1 *(LU)
    % P为置换矩阵，L为单位下三角矩阵，U为上三角矩阵
    % P通过数组表示置换矩阵，其中P(i)表示置换矩阵中第i行第P(i)列元素为1，第i行其余元素为0
    
    n=size(b,1);
    y=zeros(n,1);
    x=zeros(n,1);
    
    % 已知P, L和b, 正向求解y, 其中Ly=Pb, Ux=y, 时间复杂度为n^2
    y(1)=b(P(1));
    for ii=2:n
        sum=0;
        for jj=1:ii-1
            sum=sum+L(ii, jj)*y(jj);
        end
        y(ii)=b(P(ii))-sum;
    end
    
    % 已知U和y，反向求解x, 时间复杂度为n^2
     x(n)=y(n)/U(n, n);
    for ii=n-1:-1:1
        sum=0;
        for jj=(ii+1):n
            sum=sum+U(ii, jj)*x(jj);
        end
        x(ii)=(y(ii)-sum)/U(ii, ii);
    end
    
    % 计算结束，返回x
end