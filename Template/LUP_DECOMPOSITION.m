function [L, U, P]=LUP_DECOMPOSITION(A)
    % function [L, U, P]=LUP_DECOMPOSITION(A)
    %
    % 求矩阵L, U,P满足PA=LU, 其中 
    % A为非奇异矩阵，P为置换矩阵，L为单位下三角矩阵，U为上三角矩阵
    % 算法总体时间复杂度为n^3
    % 为了保证计算的数值稳定性，递归时将每列绝对值最大的元素移动到主元位置
    % P通过数组表示置换矩阵，其中P(i)表示置换矩阵中第i行第P(i)列元素为1，第i行其余元素为0
    
    N=size(A, 1);
    L=eye(N);
    U=zeros(N);
    P=linspace(1, N, N);
    
    for k=1:N
        p=0;
        k_=k;
        for ii=k:N
            if(abs(A(ii, k))>p)
                p=abs(A(ii,k));
                k_=ii;
            end
        end
        tmp=P(k); 
        P(k)=P(k_);
        P(k_)=tmp;
        
        for ii=1:N
            tmp=A(k, ii);
            A(k, ii)=A(k_, ii);
            A(k_, ii)=tmp;
        end
        
        for ii=(k+1):N
            A(ii,k)=A(ii, k)/A(k, k);
            for  jj=(k+1):N
                A(ii, jj)=A(ii, jj)-A(ii, k)*A(k, jj);
            end
        end
    end
    
    for ii=1:N
        for jj=1:N
            if(ii>jj)
                L(ii, jj)=A(ii, jj);
            else
                U(ii, jj)=A(ii, jj);
            end
        end
    end
    % 计算完成，返回
end