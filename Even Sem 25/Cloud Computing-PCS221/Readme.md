# PCS221 — Cloud Computing Lab Assignments

**Simran | 8025320093 | CS-02 | Thapar Institute of Engineering and Technology**

---

## Labs 1–3 — Google Colab (Python)

Basic cloud computing tasks on Google Colab — Google Colab environment exploration, NumPy matrix operations, and a full sales data analysis pipeline using Pandas and Matplotlib. Roll number used as random seed; 15% Clothing discount applied (odd roll number).

---

## Lab 4 — Azure VM + Static Website

Set up an Ubuntu 22.04 VM on Azure (East Asia), installed Apache, and hosted a two-page website (`index.html` + `contact.html`) at `http://20.205.17.23`. Also hosted a separate static site using Azure Blob Storage — no VM involved, just uploaded the HTML to a `$web` container and accessed it via the storage URL.

---

## Lab 5 — Azure Site Recovery

Replicated `lab4-vm` from East Asia to Central India using ASR. Had to downgrade the kernel from 6.8.0 to 5.15.0 (ASR Mobility Service compatibility issue) before replication worked. VM reached **Protected** status with healthy replication and ~7 min RPO. Failover wasn't possible due to Azure for Students subscription quota limits in the target region.

---

## Lab 6 — Cold Migration via Snapshot

Stopped `lab4-vm`, took a full OS disk snapshot, created a new disk and VM from it (`lab6-vm`), and verified Apache + webpage were working identically at `http://20.2.141.94`. Zero data loss, simpler than ASR but requires downtime.

---

`Azure` `Ubuntu 22.04` `Apache` `ASR` `Blob Storage` `Google Colab` `Python` `NumPy` `Pandas`
