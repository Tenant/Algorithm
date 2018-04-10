function x=LUP_SOLVE(L, U, P, b)
    % function x=LUP_SOLVE(L, U, P, b)
    %
    % ͨ��LUP�ֽ�������Է�����Ax=b, ����AΪ���������
    % �㷨����ʱ�临�Ӷ�Ϊn^2��������ֵ�ȶ���
    % PA=LU, A=P^-1 *(LU)
    % PΪ�û�����LΪ��λ�����Ǿ���UΪ�����Ǿ���
    % Pͨ�������ʾ�û���������P(i)��ʾ�û������е�i�е�P(i)��Ԫ��Ϊ1����i������Ԫ��Ϊ0
    
    n=size(b,1);
    y=zeros(n,1);
    x=zeros(n,1);
    
    % ��֪P, L��b, �������y, ����Ly=Pb, Ux=y, ʱ�临�Ӷ�Ϊn^2
    y(1)=b(P(1));
    for ii=2:n
        sum=0;
        for jj=1:ii-1
            sum=sum+L(ii, jj)*y(jj);
        end
        y(ii)=b(P(ii))-sum;
    end
    
    % ��֪U��y���������x, ʱ�临�Ӷ�Ϊn^2
     x(n)=y(n)/U(n, n);
    for ii=n-1:-1:1
        sum=0;
        for jj=(ii+1):n
            sum=sum+U(ii, jj)*x(jj);
        end
        x(ii)=(y(ii)-sum)/U(ii, ii);
    end
    
    % �������������x
end