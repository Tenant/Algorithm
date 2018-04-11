function [L, U, P]=LUP_DECOMPOSITION(A)
    % function [L, U, P]=LUP_DECOMPOSITION(A)
    %
    % �����L, U,P����PA=LU, ���� 
    % AΪ���������PΪ�û�����LΪ��λ�����Ǿ���UΪ�����Ǿ���
    % �㷨����ʱ�临�Ӷ�Ϊn^3
    % Ϊ�˱�֤�������ֵ�ȶ��ԣ��ݹ�ʱ��ÿ�о���ֵ����Ԫ���ƶ�����Ԫλ��
    % Pͨ�������ʾ�û���������P(i)��ʾ�û������е�i�е�P(i)��Ԫ��Ϊ1����i������Ԫ��Ϊ0
    
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
    % ������ɣ�����
end