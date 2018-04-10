function [L, U]=LU_DECOMPOSITION(A)
    % ��Գ���������A��LU�ֽ⣬����֤���Գ���������ֽ�����в�������������
    % �÷���ͬ�������ڵ��������в�������������ķ���������LUP�ֽ⣬����PΪ��λ��
    % LΪ��λ�����Ǿ���UΪ�����Ǿ���
    
    N=size(A,1);
    L=eye(N);
    U=zeros(N);
     
    for ii=1:N
        % ģ���˹��Ԫ����L��U
        U(ii, ii)=A(ii, ii);
        for jj=(ii+1):N
            L(jj, ii)=A(jj, ii)/U(ii, ii);
            U(ii, jj)=A(ii, jj);
        end
        
        % �Ծ���A���ø�˹��Ԫ��
        for jj=(ii+1):N
            for kk=(ii+1):N
                A(jj, kk)=A(jj, kk)-L(jj, ii)*U(ii, kk);
            end
        end
    end
    
    % �������������L��U
end