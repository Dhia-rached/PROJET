--------------------------------------------------------
--  Fichier cr�� - mercredi-novembre-03-2021   
--------------------------------------------------------
DROP TABLE "KIRAXER"."EMPLOYES";
DROP TABLE "KIRAXER"."LOCAL";
DROP TABLE "KIRAXER"."LOCATION";
DROP TABLE "KIRAXER"."MATERIEL";
DROP TABLE "KIRAXER"."PUBLICITE";
DROP TABLE "KIRAXER"."VEHICULE";
--------------------------------------------------------
--  DDL for Table EMPLOYES
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."EMPLOYES" 
   (	"CIN" NUMBER, 
	"NOM" VARCHAR2(20 BYTE), 
	"PRENOM" VARCHAR2(20 BYTE), 
	"ADR" VARCHAR2(20 BYTE), 
	"SALAIRE" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOCAL
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."LOCAL" 
   (	"CORDONNES" VARCHAR2(20 BYTE), 
	"SURFACE" VARCHAR2(20 BYTE), 
	"DATE_LOC" VARCHAR2(20 BYTE), 
	"COLUMN4" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table LOCATION
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."LOCATION" 
   (	"ID_LOCATION" VARCHAR2(20 BYTE), 
	"DUREE" VARCHAR2(20 BYTE), 
	"ETAT" VARCHAR2(20 BYTE), 
	"PRIX" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table MATERIEL
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."MATERIEL" 
   (	"NUM_SERIE" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"COLUMN1" VARCHAR2(20 BYTE), 
	"PRIX" VARCHAR2(20 BYTE), 
	"NOM_FORNISSEUR" VARCHAR2(20 BYTE), 
	"NOM_MATERIEL" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table PUBLICITE
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."PUBLICITE" 
   (	"ID_PUB" VARCHAR2(20 BYTE), 
	"TYPE" VARCHAR2(20 BYTE), 
	"DATE_PUB" VARCHAR2(20 BYTE), 
	"PRIX" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Table VEHICULE
--------------------------------------------------------

  CREATE TABLE "KIRAXER"."VEHICULE" 
   (	"MATRICULE" VARCHAR2(20 BYTE), 
	"MARQUE" VARCHAR2(20 BYTE), 
	"DATE_ENTR�E" VARCHAR2(20 BYTE), 
	"PRIX" VARCHAR2(20 BYTE), 
	"COULEUR" VARCHAR2(20 BYTE)
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
REM INSERTING into KIRAXER.EMPLOYES
SET DEFINE OFF;
REM INSERTING into KIRAXER.LOCAL
SET DEFINE OFF;
REM INSERTING into KIRAXER.LOCATION
SET DEFINE OFF;
REM INSERTING into KIRAXER.MATERIEL
SET DEFINE OFF;
REM INSERTING into KIRAXER.PUBLICITE
SET DEFINE OFF;
REM INSERTING into KIRAXER.VEHICULE
SET DEFINE OFF;
--------------------------------------------------------
--  DDL for Index EMPLOYES_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."EMPLOYES_PK" ON "KIRAXER"."EMPLOYES" ("CIN") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index LOCAL_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."LOCAL_PK" ON "KIRAXER"."LOCAL" ("CORDONNES") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index LOCATION_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."LOCATION_PK" ON "KIRAXER"."LOCATION" ("ID_LOCATION") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index MATERIEL_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."MATERIEL_PK" ON "KIRAXER"."MATERIEL" ("NUM_SERIE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index PUBLICITE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."PUBLICITE_PK" ON "KIRAXER"."PUBLICITE" ("ID_PUB") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  DDL for Index VEHICULE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KIRAXER"."VEHICULE_PK" ON "KIRAXER"."VEHICULE" ("MATRICULE") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM" ;
--------------------------------------------------------
--  Constraints for Table EMPLOYES
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."EMPLOYES" ADD CONSTRAINT "EMPLOYES_PK" PRIMARY KEY ("CIN")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 COMPUTE STATISTICS 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."EMPLOYES" MODIFY ("CIN" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LOCAL
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."LOCAL" ADD CONSTRAINT "LOCAL_PK" PRIMARY KEY ("CORDONNES")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."LOCAL" MODIFY ("CORDONNES" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LOCATION
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."LOCATION" ADD CONSTRAINT "LOCATION_PK" PRIMARY KEY ("ID_LOCATION")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."LOCATION" MODIFY ("ID_LOCATION" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table MATERIEL
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."MATERIEL" ADD CONSTRAINT "MATERIEL_PK" PRIMARY KEY ("NUM_SERIE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."MATERIEL" MODIFY ("NOM_MATERIEL" NOT NULL ENABLE);
  ALTER TABLE "KIRAXER"."MATERIEL" MODIFY ("NUM_SERIE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table PUBLICITE
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."PUBLICITE" ADD CONSTRAINT "PUBLICITE_PK" PRIMARY KEY ("ID_PUB")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."PUBLICITE" MODIFY ("ID_PUB" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table VEHICULE
--------------------------------------------------------

  ALTER TABLE "KIRAXER"."VEHICULE" ADD CONSTRAINT "VEHICULE_PK" PRIMARY KEY ("MATRICULE")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1 BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "SYSTEM"  ENABLE;
  ALTER TABLE "KIRAXER"."VEHICULE" MODIFY ("MATRICULE" NOT NULL ENABLE);
