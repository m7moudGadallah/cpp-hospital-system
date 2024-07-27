# Hospital Management System Requirements

- Implement a simple hospital management system in C++.
- There are 20 different specializations in the hospital. (e.g., Cardiology, Neurology, Children, Surgery, etc.)
- For each specialization, there are only 5 available spots [queue]
- Adding a patient
  - Read the requested specialization from the user [1 - 20].
  - Read his name and status (0 = regular, 1 = urgent).
  - if 5 patients exist, apologize and don't accept the patient.
  - if the user is regular, add in end of queue. otherwise, add in Begin
- Print patients, for the specializations that have waiting patients.
- Dr pickup a patient
  - Read the requested specialization. if no patients, inform the doctor.
  - otherwise, ask the patient to go with the Dr. Remove from the queue.
