function plotKiteState(X1, YMatrix1, labelY)
%CREATEFIGURE(X1,YMATRIX1)
%  X1:  vector of x data
%  YMATRIX1:  matrix of y data

%  Auto-generated by MATLAB on 08-Oct-2010 12:27:50

% Create figure
figure1 = figure('XVisual',...
    '0x77 (TrueColor, depth 32, RGB mask 0xff0000 0xff00 0x00ff)');

% Create axes
axes1 = axes('Parent',figure1,'FontSize',20);
% Uncomment the following line to preserve the X-limits of the axes
xlim(axes1,[0 36]);
box(axes1,'on');
hold(axes1,'all');

% Create multiple lines using matrix input to plot
plot1 = plot(X1,YMatrix1,'Color',[0 0 0]);
set(plot1(1),'LineWidth',3);
set(plot1(2),'LineWidth',1,'LineStyle','--');

% Create xlabel
xlabel('time [s]','FontWeight','bold','FontSize',28);

% Create ylabel
ylabel(labelY,'FontWeight','bold','FontSize',28);

