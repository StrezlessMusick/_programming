clear;

p=[2
0
0
7
2
2
0
3
6
6
0
5
2
2
2
2
3
2
2
4
2
2
3
3
5
2
1
3
3
2
2
2
2
5
0
1
1
3
3
4
3
4
2
1
3
2
4
4
4
2
3
0
1
3
4
2
0
0
3
2
3
2
4
2
2
1
3
2
4
1
4
1
2
3
2
4
2
0
5
4
4
5
4
2
2
1
2
1
2
1
3
5
1
3
3
2
5
3
2
3
];

g=[
    27
28
27
36
17
15
31
26
36
27
20
27
29
24
20
40
28
37
27
24
25
26
30
19
32
25
23
23
33
24
27
33
26
25
29
23
25
23
20
26
40
30
17
25
24
16
30
28
22
29
30
34
40
27
33
26
21
26
37
30
34
33
27
27
32
23
18
25
21
29
33
23
23
21
27
31
25
25
27
35
28
33
20
26
21
24
28
22
34
32
24
27
37
30
26
29
21
32
26
28
];


clc
p=g';
i=1:max(p)+1;
for q=i;
    stp(q)=0;
end;
l=length(p);
%plot(i-1,stp);

for a=p;
    %q=stp(a+1);
    stp(a+1)=stp(a+1)+1;
    %disp([a,666,q,stp(a+1)]);
end;
stp=stp./length(p);
%hist(p,(1:max(p))-0.5);

sr=0;
for q=1:l
    sr=sr+p(q);
end;
sr=sr/l


bar([i-1,max(i)],[stp,0],1,'b');%,'.-');

D=0;
for q=1:l
    D=D+(p(q)-sr).^2;
end;
D=D/l;
c=D^0.5
%
hold on;
%i-1
x=[i-1,max(i):round(max(i)*1.2)];
%sr.^x
%fact(x)
%1./fact(x)
%exp(-sr)
puass=((sr.^x)./fact(x)).*exp(-sr);
bar(x,puass,0.5,'r');%,'r.-');
%
n=0:0.01:round(max(i)*1.2);
gauss=1/(2*pi*D)^0.5.*exp(-(n-sr).^2./2./D);
plot(n,gauss,'.r')

%bar([i-1,max(i)],[stp,0],1,'b');%,'.-');







