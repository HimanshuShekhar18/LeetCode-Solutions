% Q1) Determine whether the system is Linear or non-Linear


% Define two input signals x1(n) and x2(n) (you can modify these signals)
n = -10:10; % Define a range of n values
x1 = randn(size(n)); % Random input signal 1 (replace with your input)
x2 = randn(size(n)); % Random input signal 2 (replace with your input)

% Calculate the outputs y1(n) = x1(-n) and y2(n) = x2(-n)
y1 = fliplr(x1); % Flip the first input signal
y2 = fliplr(x2); % Flip the second input signal

% Constants A and B (you can modify these constants)
A = 2;
B = -3;

% Calculate the combined output
y_combined = A * y1 + B * y2;

% Calculate the output for the combined input
x_combined = A * x1 + B * x2;
y_expected = fliplr(x_combined); % Flip the combined input signal

% Check if the system is linear or nonlinear
is_linear = isequal(y_combined, y_expected);

if is_linear
    disp('The system is linear.');
else
    disp('The system is nonlinear.');
end


