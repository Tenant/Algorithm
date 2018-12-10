function A_=LUP_InverseMatrix(A)
    % function A_=LUP_InverseMatrix(A)
    %
    % ����LUP�ֽ�Ծ�������
    % �㷨����ʱ�临�Ӷ�Ϊn^3

    N=size(A,1);
    A_=zeros(N,N);
    E=eye(N);
    [L, U, P]=LUP_DECOMPOSITION(A);
    for ii=1:N
        A_(:, ii)=LUP_SOLVE(L, U, P, E(:, ii));
    end

    % ������ɣ�����A_
end