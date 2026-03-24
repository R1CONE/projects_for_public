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
