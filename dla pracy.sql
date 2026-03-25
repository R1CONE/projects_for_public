SELECT * FROM CDN.TraNag Order By TrN_DataDok DESC
SElECT * FROM CDN.TraNag WHERE TrN_Termin = '2026-03-18';
UPDATE CDN.TraNag SET Trn_Bufor = 0 WHERE TrN_TrNID = 533;




SELECT TOP (1000) Knt_KntId

select * from cdn.PracEtaty
select * from cdn.Pracidx


SELECT TOP (1000) [TrN_TrNID]
      ,[TrN_TerminZwrotuKaucji]
      ,[TrN_OFFPrawoDoFAPA]
      ,[TrN_OFFPrawoDoAnulowania]
      ,[TrN_RelTrNId]
      ,[TrN_FVMarza]



select TrNNumerPelny,trn * FROM [CDN_Firma_Demo_1_1].[CDN].[TraNag] WHERE TrN_NumerPelny LIKE 'FZ%'

select * from cdn.Pracidx

CREATE PROCEDURE idk
    @PriId int
AS
BEGIN
    DECLARE @TrN_TrNId int;
    SELECT @TrN_TrNId = TrN_TrNID FROM CDN.TraNag WHERE TrN_OdbiorcaTyp = 3 AND TrN_OdbID = @PriId AND TrN_NumerString LIKE 'FZ%'
END;
R1CONE [cvrs],  — Вчера, в 12:27
CREATE PROCEDURE idk
    @PriId int
AS
BEGIN
    DECLARE @TrN_TrNId int;

    SELECT TOP 1 
        @TrN_TrNId = TrN_TrNID
    FROM CDN.TraNag
    WHERE TrN_OdbiorcaTyp = 3 
      AND TrN_OdbID = @PriId
      AND TrN_NumerString LIKE 'FZ%'
    ORDER BY TrN_DataWys DESC;

END;



CREATE PROCEDURE idk
    @PriId int
AS
BEGIN

    DECLARE @TrNId int;

    SELECT TOP 1 @TrNId = TrN_TrNID FROM CDN.TraNag
    WHERE TrN_OdbiorcaTyp = 3
    AND TrN_OdbID = @PriId
    AND TrN_NumerString LIKE 'FZ%'
    ORDER BY TrN_TrNId DESC

    DECLARE @KrNId int;

    SELECT @KrNId = TrN_PlatnikID FROM CDN.TraNag
    WHERE TrN_TrNID = @TrNId;

    print @TrNId;
    print @KrNId;


END;
R1CONE [cvrs],  — Вчера, в 14:01
select * from cdn.DefProjekty
  select * from cdn.Dzialy
  select * from cdn.tranag
  select * from cdn.Wymiary
  select * from cdn.WymiaryWartosci
R1CONE [cvrs],  — Вчера, в 14:14
select * from cdn.Dzialy - названия всех видов дейтельностей куда может пойти процент
select * from cdn.WymiaryWartosci -- таблица с вартощсиами этих хуен
R1CONE [cvrs],  — 10:16
DZL_Dzlld.Dzialy =
select * from cdn.Dzialy
select * from cdn.WymiaryWartosci
R1CONE [cvrs],  — 11:13
Maciej 19 - by 1 to 19


USE [CDN_Firma_Demo_1_1]
GO
/****** Object:  StoredProcedure [dbo].[SearchAllTables]    Script Date: 24.03.2026 10:29:55 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- Source - https://stackoverflow.com/a/19846145
-- Posted by Rafi, modified by community. See post 'Timeline' for change history
-- Retrieved 2026-03-20, License - CC BY-SA 3.0

ALTER PROC [dbo].[SearchAllTables]
(
@SearchStr nvarchar(100)
)
AS
BEGIN

    CREATE TABLE #Results (ColumnName nvarchar(370), ColumnValue nvarchar(3630))

    SET NOCOUNT ON

    DECLARE @TableName nvarchar(256), @ColumnName nvarchar(128), @SearchStr2 nvarchar(110)
    SET  @TableName = ''
    SET @SearchStr2 = QUOTENAME('%' + @SearchStr + '%','''')

    WHILE @TableName IS NOT NULL

    BEGIN
        SET @ColumnName = ''
        SET @TableName = 
        (
            SELECT MIN(QUOTENAME(TABLE_SCHEMA) + '.' + QUOTENAME(TABLE_NAME))
            FROM     INFORMATION_SCHEMA.TABLES
            WHERE         TABLE_TYPE = 'BASE TABLE'
                AND    QUOTENAME(TABLE_SCHEMA) + '.' + QUOTENAME(TABLE_NAME) > @TableName
                AND    OBJECTPROPERTY(
                        OBJECT_ID(
                            QUOTENAME(TABLE_SCHEMA) + '.' + QUOTENAME(TABLE_NAME)
                             ), 'IsMSShipped'
                               ) = 0
        )

        WHILE (@TableName IS NOT NULL) AND (@ColumnName IS NOT NULL)

        BEGIN
            SET @ColumnName =
            (
                SELECT MIN(QUOTENAME(COLUMN_NAME))
                FROM     INFORMATION_SCHEMA.COLUMNS
                WHERE         TABLE_SCHEMA    = PARSENAME(@TableName, 2)
                    AND    TABLE_NAME    = PARSENAME(@TableName, 1)
                    AND    DATA_TYPE IN ('char', 'varchar', 'nchar', 'nvarchar', 'int', 'decimal')
                    AND    QUOTENAME(COLUMN_NAME) > @ColumnName
            )

            IF @ColumnName IS NOT NULL

            BEGIN
                INSERT INTO #Results
                EXEC
                (
                    'SELECT ''' + @TableName + '.' + @ColumnName + ''', LEFT(' + @ColumnName + ', 3630) 
                    FROM ' + @TableName + 'WITH (NOLOCK) ' +
                    ' WHERE ' + @ColumnName + ' LIKE ' + @SearchStr2
                )
            END
        END    
    END

    SELECT ColumnName, ColumnValue FROM #Results
END

--------------


SELECT * FROM CDN
SELECT * FROM CDN.WymiaryWartosci -- WyW_WyyID
SELECT * FROM CDN.Kategorie WHERE Kat_KatID = 49
select * from cdn.Pracidx
SELECT * FROM cdn.Dzialy
select * from cdn.DefProjekty
select * from cdn.opiskadry WHERE OPK_PraId = 19 -- OPK_OpkId --   ---- OPK_RodzajZrodla --16 
select * FROM CDN.DokKodyJPKV7

SELECT * FROM CDN.Konta 


EXEC FindColumnInDatabase '%SlownikID%' 
-- 

SELECT * FROM CDN.WymiaryWartosci JOIN CDN.DokKodyJPKV7 ON CDN.WymiaryWartosci.WyW_LpPozycji = CDN.DokKodyJPKV7.DKV7_ParentTyp
select * FROM CDN.DokKodyJPKV7

UPDATE CDN.Kategorie SET Kat_Opis = 'Project rodzaju P3' WHERE Kat_KatID = 169;



EXEC SearchAllTablesInt 16;

select kat.Kat_KodSzczegol,d.DZL_Nazwa,d.DZL_Kod,dp.PRJ_Nazwa,dp.PRJ_Kod,tn.TrN_PodID,k.Knt_Nazwa1,TrN_TrNID,TrN_NumerPelny,* from cdn.pracidx pix        -- tu jest id pracownika
join cdn.UmowyB2B ub on ub.UMB_PraId=pix.PRI_PraId -- tu są umowy b2b
join cdn.OpisKadry ok on ok.OPK_PraId=pix.PRI_PraId -- tu jest opis analityczny PRACOWNIKA
join cdn.dzialy d on d.DZL_DzlId=ok.OPK_DzlId -- Tu są nazwy o akronimy działów wydziałów
join cdn.DefProjekty dp on dp.PRJ_PrjId=ok.OPK_PrjId --  tu są definicje projektów
join cdn.TraNag tn on tn.TrN_PodID=ub.UMB_KntId  -- znajduję fakturę z kontrahentem z umowy b2b
join cdn.Kontrahenci k on k.knt_kntid=tn.trn_podid -- łączem z nazwą kontrahenta
join cdn.Kategorie kat on kat.Kat_KodSzczegol=dp.PRJ_Kod 
WyW_WyyID
-- slownik id  0 165 167 0 163 49 164

SELECT * FROM cdn.OpisKadry -- Kat_RodzajZakupu 
SELECT * FROM CDN.TraNAg

SELECT * FROM CDN.WymiaryWartosci



EXEC dbo.SearchAllTablesInt 167;  

[CDN].[TraNag]	[TrN_KatID]	167
[CDN].[TraNag]	[TrN_OdbID]	167
[CDN].[TraNag]	[TrN_OdbID]	167
[CDN].[TraNag]	[TrN_PlatnikID]	167
[CDN].[TraNag]	[TrN_PlatnikID]	167
[CDN].[TraNag]	[TrN_PodID]	167
[CDN].[TraNag]	[TrN_PodID]	167

SELECT * FROM CDN.WymiaryWartosci
LEFT Join CDN.Kategorie On CDN.Kategorie.Kat_KatID = CDN.WymiaryWartosci.WyW_SlownikId

SELECT * FROM CDN.TraNAg WHERE [TrN_KatID] = 167

SELECT * FROM CDN.TraNAg

SELECT * FROM CDN.Kategorie

SELECT *
FROM CDN.Kategorie
WHERE CDN.Kategorie.Kat_KatID IN (149, 152, 153, 51, 52, 53, 55, 56, 57, 58, 59, 156, 157, 159, 160); --55

FAPF/@numerS/2026FA/@numerS/2026 

 ------------------

EXEC SearchAllTables 'PRZYCHODY POZOSTAŁE';

select * from CDN.Kategorie

select * FROM CDN.DokKodyJPKV7



select * FROM CDN.Towary

SELECT * FROM CDN.RejestrOperacji


SELECT Kat_KatId, Kat_KodSzczegol, Kat_Opis,
(SELECT STUFF((SELECT '; ' + KV7_Kod FROM CDN.DokKodyJPKV7 
JOIN CDN.KodyJPKV7 ON DKV7_KV7ID = KV7_KV7ID WHERE DKV7_ParentTyp = 3 
AND DKV7_ParentID = Kat_KatID FOR XML PATH('')) , 1, 2, ''))
AS KodyJPKV7, Kat_KodOgolny, Kat_Poziom, Kat_ParentID, Kat_Nieaktywny 
select * FROM CDN.Kategorie -- 154 
