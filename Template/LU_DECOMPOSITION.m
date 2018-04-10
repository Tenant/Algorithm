function [L, U]=LU_DECOMPOSITION(A)
    % 求对称正定矩阵A的LU分解，可以证明对称正定矩阵分解过程中不会产生除零错误
    % 该方法同样可用于迭代过程中不会产生除零错误的非奇异矩阵的LUP分解，其中P为单位阵
    % L为单位下三角矩阵，U为上三角矩阵
    
    N=size(A,1);
    L=eye(N);
    U=zeros(N);
     
    for ii=1:N
        % 模拟高斯消元法求L和U
        U(ii, ii)=A(ii, ii);
        for jj=(ii+1):N
            L(jj, ii)=A(jj, ii)/U(ii, ii);
            U(ii, jj)=A(ii, jj);
        end
        
        % 对矩阵A采用高斯消元法
        for jj=(ii+1):N
            for kk=(ii+1):N
                A(jj, kk)=A(jj, kk)-L(jj, ii)*U(ii, kk);
            end
        end
    end
    
    % 计算结束，返回L和U
end