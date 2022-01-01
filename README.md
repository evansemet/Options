# European Options Portfolio Analyzer

** This is a current project that I am working on and still needs to be tested and have more features added


Currently, it takes a portfolio of positions of European options and will calculate the total fair market value of the portfolio using the Black Scholes model and sum up 18 different Greeks to display the total risk of the portfolio. It can go through over 15,000 positions in a portfolio per second.

To demonstrate:
Assume that the entire portfolio consists of only one options call contract with the following characteristics 150.00 current stock price, 170.00 strike price, the current risk free investment rate is 5.00% (0.0500), the dividend yield of the underlying stock is 2.00% (0.0200), the expiration date of the option is 6 months away (0.5 years), and the volatility of the underlying stock is 25.00% (0.2500).
The program will take that information and display the following:



Fair Market Value of Portfolio: 4.89339



First Order Greeks:

TotalDelta: 0.296102

TotalVega: 36.3111

Total Theta: -10.2476

Total Rho: 19.7609

Total Epsilon: -22.0087

Total Lambda: 9.07659



Second Order Greeks:

Total Gamma: 0.0129106

Total Vanna: 0.974402

Total Charm: -0.295829

Total Vomma: 55.2709

Total Veta: 52.6981

Total Varphi: 0.00466879



Third Order Greeks:

Total Speed: 0.000174312

Total Zomma: -0.0319906

Total Color: -0.00714818

Total Ultima: -597.276

Total Dual Delta: -0.232482

Total Dual Gamma: 0.0100515

