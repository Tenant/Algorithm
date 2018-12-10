function A_=LUP_InverseMatrix(A)
    % function A_=LUP_InverseMatrix(A)
    %
    % 利用LUP分解对矩阵求逆
    % 算法总体时间复杂度为n^3

    N=size(A,1);
    A_=zeros(N,N);
    E=eye(N);
    [L, U, P]=LUP_DECOMPOSITION(A);
    for ii=1:N
        A_(:, ii)=LUP_SOLVE(L, U, P, E(:, ii));
    end

    % 计算完成，返回A_
end