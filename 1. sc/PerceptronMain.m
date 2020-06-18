 
M = csvread('pima-indians-diabetes.data.txt');
x_m = (M(:,1:end-1));
y_m = (M(:,end))*2-1;

etas = [0.001, 0.002, 0.005, 0.01, 0.02, 0.5];
Ts = [100, 500, 1000, 2000];

index60 = 461;
index20 = 615;

fid1 =fopen('DiabetesTrain.txt','wb');
fwrite(fid,M(1:index60,:)
fid2 =fopen('DiabetesValidation.txt','wb');
fid3 =fopen( 'DiabetesTest.txt', 'wb');


x = (x_m(1:index60,:));
y = (y_m(1:index60,:));

for eta = etas
  for T = Ts  
    w1 = PerceptronTrain(x, y, eta, T);
  end
end

x = (x_m(index60+1:index20,:));
y = (y_m(index60+1:index20,:));

%for eta = etas
%  for T = Ts 
%    w2 = PerceptronTrain(x, y, eta, T);
% end
% end

final_x = (x_m(index20+1:end,:));
final_y = PerceptronTest(x, w);
y2 = PerceptronTest(x, w2);
disp(y2)
