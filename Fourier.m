n=4;
hold on
x=[ 0 1 2 3 4 5];
y=[0 0 1 1 0 0];
q=linspace(0,5,5000)
for z=1:5000
	q(z)=q(z)+0.0001;
end
p=((0<=q)&(q<=0.5)).*(1)+((0.5<q)&(q<1.5)).*(0)+((1.5<=q)&(q<=2.5)).*(1)+((2.5<q)&(q<3.5)).*(0)+((3.5<=q)&(q<=4.5)).*(1);
plot(q,p,'b');
x=linspace(0,5,5000);
for v=1:5000
	x(v)=x(v)+0.001;
end
y=zeros(length(x),1);
for i=1:length(x)
    y(i)=1/2;
    for k=1:2:n
        y(i)=y(i)+(-1)^((k-1)/2)*2*cos(k*pi*x(i))/(k*pi);
     end
end
plot(x,y, 'r');
title(sprintf('Aproximación de Fourier: %i términos',n))
xlabel('t'); ylabel('f(t)')
hold off