Dennis Ward CS305 12/6/2023

Artemis Financial, a prominent financial institution, enlisted our expertise to bolster the security of their application. The project's primary objective was to conduct a thorough vulnerability assessment and implement robust security measures.

In addressing the software security vulnerabilities, a meticulous approach was taken. Utilizing dependency checks and a comprehensive code review, we identified and analyzed potential weaknesses. A significant challenge encountered was the presence of outdated libraries within the project, complicating both the assessment process and subsequent modifications.

To fortify the application, a secure hash function was implemented to enhance data integrity, and a RESTful HTTPS connection was established to secure communication in transit. Additionally, a custom Certificate Authority (CA) was created to issue certificates, adding an extra layer of security to the communication process. Recognizing the importance of adhering to secure coding practices, these measures aimed not only to address immediate concerns but also to contribute to the overall well-being of Artemis Financial by safeguarding sensitive information and maintaining client trust.

The vulnerability assessment process was enriched by referencing a vulnerability assessment flow diagram, outlining seven critical points from the vulnerability assessment flow diagram for maintaining secure code. Maven Dependency Check emerged as a valuable tool, ensuring the integrity of the codebase by identifying and addressing potential security issues. In instances where vulnerabilities could not be immediately addressed, a suppression file was employed to manage false positives, ensuring a pragmatic approach to security mitigation.

Enhancing layers of security extended beyond the measures. Continuous monitoring systems, access controls, and encryption protocols were strategically incorporated to establish a comprehensive security posture.

Looking forward, future vulnerability assessments would benefit from a holistic approach, combining established tools like Maven Dependency Check with advanced methodologies to make informed decisions on mitigation techniques. This proactive stance ensures the ongoing resilience of the software against emerging threats.

To ascertain both functionality and security after refactoring, rigorous testing procedures were implemented. These included systematic code reviews, penetration testing, and dynamic analysis to identify and rectify any newly introduced vulnerabilities. This multi-faceted testing approach aimed to strike a balance between functionality and security, mitigating risks associated with code alterations.

Throughout the assignment, industry-standard tools such as static analysis tools and penetration testing frameworks were employed. Additionally, strict adherence to secure coding practices and a commitment to industry standards contributed to a comprehensive and effective security strategy.

In presenting examples to future employers, the ability to navigate and secure older applications, coupled with the successful utilization of Maven Dependency Check and the creation of a custom Certificate Authority, stands as a testament to the capacity to fortify software security. The tangible results achieved in terms of vulnerability identification, mitigation, and overall system enhancement serve as compelling evidence of expertise in ensuring the security and functionality of mission-critical applications.
